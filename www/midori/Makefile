# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	midori
PORTVERSION=	0.4.7
CATEGORIES=	www xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	webkitgtk-1:${PORTSDIR}/www/webkit-gtk2 \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-libnotify \
		--enable-addons \
		--enable-docs \
		--disable-gtk3

# if user has set DISABLE_MAKE_JOBS, then MAKE_JOBS_NUMBER is undefined
.if defined(DISABLE_MAKE_JOBS)
CONFIGURE_ARGS+=--jobs=1
.else
CONFIGURE_ARGS+=--jobs=${MAKE_JOBS_NUMBER}
.endif

MAKE_JOBS_SAFE=	yes
HAS_CONFIGURE=	yes
USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2 desktopfileutils
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

PLIST_SUB=	VERSION="${PORTVERSION:R}" \
	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	APIDOCS NLS UNIQUE
OPTIONS_DEFAULT=	NLS UNIQUE

APIDOCS_DESC=	Build API documentation
UNIQUE_DESC=	Single instance support

.include <bsd.port.options.mk>

# WAF needs that
CONFIGURE_ENV+=	CC="${CC}"

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MAPIDOCS}
BUILD_DEPENDS+=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-apidocs
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--disable-apidocs
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=--enable-unique
.else
CONFIGURE_ARGS+=--disable-unique
.endif

pre-patch:
# Disable HTTP Strict Transport Security (hsts)
	@cd ${WRKSRC}/katze && ${RM} midori-hsts.vala

post-install:
	@-update-desktop-database
.if ${PORT_OPTIONS:MAPIDOCS}
	${MKDIR} ${DOCSDIR}/api/katze/html
	${MKDIR} ${DOCSDIR}/api/midori/html
	(cd ${WRKSRC}/_build/docs/api/katze/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/katze/html)
	(cd ${WRKSRC}/_build/docs/api/midori/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/midori/html)
.endif

.include <bsd.port.mk>
