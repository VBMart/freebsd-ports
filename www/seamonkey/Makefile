# Created by: eivind/dima/jseger
# $FreeBSD$

PORTNAME=	seamonkey
DISTVERSION=	2.14
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}/source
DISTFILES=	seamonkey-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	seamonkey-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.9:${PORTSDIR}/devel/nspr \
		nss>=3.13.6_1:${PORTSDIR}/security/nss \
		sqlite3>=3.7.12.1:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		unzip:${PORTSDIR}/archivers/unzip

EM_VERSION=	1.4.6

USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=-2.7
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	gecko
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
WANT_PERL=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	default
USE_GL=		gl
MAKE_JOBS_SAFE=	yes
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--program-transform-name='s/seamonkey/${MOZILLA}/' \
		--enable-application=suite

USE_MOZILLA=	# empty
MOZ_PKGCONFIG_FILES=

NOT_FOR_ARCHS=	ia64

OPTIONS_DEFINE=	CHATZILLA COMPOSER ENIGMAIL GSTREAMER LDAP LIGHTNING MAILNEWS
OPTIONS_DEFAULT=CHATZILLA COMPOSER ENIGMAIL GIO LDAP LIGHTNING MAILNEWS

CHATZILLA_DESC?=Chatzilla IRC module
COMPOSER_DESC?=	HTML Composer module
LDAP_DESC?=	LDAP support for Mailnews
MAILNEWS_DESC?=	Mail and News modules

.include "${.CURDIR}/../../www/firefox/Makefile.options"

OPTIONS_DEFAULT:=${OPTIONS_DEFAULT:S/OSS/ALSA/}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHATZILLA}
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-release
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
MOZ_EXPORT+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if ! ${PORT_OPTIONS:MMAILNEWS}
EXTRA_PATCHES+=	${FILESDIR}/extra-mailnews-patch-bridge-bridge.mk \
		${FILESDIR}/extra-patch-configure.in
MOZ_OPTIONS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if ! ${PORT_OPTIONS:MLDAP}
MOZ_OPTIONS+=	--disable-ldap --enable-mailnews
.else
MOZ_OPTIONS+=	--enable-ldap --enable-mailnews
.endif
.if ${PORT_OPTIONS:MENIGMAIL}
MASTER_SITES+=	http://www.enigmail.net/download/source/:enigmail
DISTFILES+=	${EM_DISTFILE}:enigmail
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
EM_DISTNAME=	enigmail-${EM_VERSION}
EM_DISTFILE=	${EM_DISTNAME}.tar.gz
EM_XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/bin/${EM_DISTNAME}-freebsd-${ARCH:S/amd64/x86_64/}.xpi
EM_ORIG_ID=	{847b3a00-7ab1-11d4-8f02-006008948af5}
EM_ID=		${PORTNAME}@mozilla-enigmail.org
EM_ID_RFILES=	${XPI_LIBDIR}/${EM_ID}/install.rdf \
		${XPI_LIBDIR}/${EM_ID}/components/enigmail.js \
		${XPI_LIBDIR}/${EM_ID}/modules/enigmailCommon.jsm
.endif
.endif

.if ! ${PORT_OPTIONS:MCOMPOSER}
MOZ_OPTIONS+=	--disable-composer
.endif

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/xpi-stage/lightning.xpi
XPI_ORIG_ID=	{e2fda1a4-762b-4020-b5ad-a41df1933103}
XPI_ID=		lightning@seamonkey.mozilla.org
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
post-extract:
	@${TAR} -xf ${_DISTDIR}/${EM_DISTFILE} \
		-C ${WRKSRC}/mailnews/extensions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/suite/app/nsSuiteApp.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/src/init/all.js
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/${MOZILLA}.desktop
.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
		${WRKSRC}/mailnews/extensions/enigmail/makemake
	@${REINPLACE_CMD} -e '/^xpi/s/$$/ all/' \
		-e '/^XPI_MODULE_VERS/s/= .*/= ${EM_VERSION}/' \
		${WRKSRC}/mailnews/extensions/enigmail/Makefile.in
	@${REINPLACE_CMD} -e '/em:version/s,>[^<]*<,>${EM_VERSION}<,' \
		-e '/em:maxVersion/s/pre//' \
		${WRKSRC}/mailnews/extensions/enigmail/package/install.rdf
.endif

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
post-build:
	cd ${WRKSRC}/mailnews/extensions/enigmail && \
		./makemake -r -o ${MOZ_OBJDIR}
	${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} all xpi \
		-C ${MOZ_OBJDIR}/mailnews/extensions/enigmail
.endif

pre-install:
	${ECHO_CMD} share/applications/${MOZILLA}.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${MOZILLA}.png' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png \
		${PREFIX}/share/pixmaps/${MOZILLA}.png

post-install:
.if ${PORT_OPTIONS:MLIGHTNING}
	@${MKDIR} ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey
	@(cd ${XPI_LIBDIR}/${XPI_ID}; ${TAR} -xf ${XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${XPI_ID}
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/seamonkey/${XPI_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/seamonkey/extensions/${XPI_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${MKDIR} ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME}
	@(cd ${XPI_LIBDIR}/${EM_ID}; ${TAR} -xf ${EM_XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${EM_ID}
	@${REINPLACE_CMD} -i "" "s/${EM_ORIG_ID}/${EM_ID}/" ${EM_ID_RFILES}
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${EM_ID}
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME} 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/${PORTNAME}/${EM_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/${PORTNAME}/extensions/${EM_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MLIGHTNING} || ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/${PORTNAME} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
