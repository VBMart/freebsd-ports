# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	rancid
PORTVERSION=	2.3.8
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/rancid/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Really Awesome New Cisco confIg Differ

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect-devel
RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect-devel \
		p5-LockFile-Simple>=0:${PORTSDIR}/devel/p5-LockFile-Simple

USE_PERL5=	yes
SUB_FILES=	pkg-message
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var/${PORTNAME}/ \
		--bindir=${PREFIX}/libexec/${PORTNAME}/ \
		--sysconfdir=${PREFIX}/etc/${PORTNAME}/

MAN1=		agmrancid.1 alogin.1 arancid.1 arrancid.1 avologin.1 avorancid.1 \
		blogin.1 brancid.1 cat5rancid.1 clogin.1 \
		control_rancid.1 cssrancid.1 elogin.1 erancid.1 f10rancid.1 \
		f5rancid.1 flogin.1 fnrancid.1 francid.1 hlogin.1 hrancid.1 \
		htlogin.1 htrancid.1 jerancid.1 jlogin.1 jrancid.1 lg_intro.1 \
		mrancid.1 mrvlogin.1 mrvrancid.1 mtlogin.1 mtrancid.1 \
		nlogin.1 nrancid.1 nslogin.1 nsrancid.1 nxrancid.1 fnlogin.1 \
		par.1 prancid.1 rancid-cvs.1 rancid-run.1 rancid.1 \
		rancid_intro.1 rivlogin.1 rivrancid.1 \
		rrancid.1 srancid.1 tlogin.1 tntlogin.1 tntrancid.1 trancid.1 \
		xrancid.1 xrrancid.1 zrancid.1

MAN5=		lg.conf.5 cloginrc.5 rancid.conf.5 router.db.5

OLDCONFIG_FILE1=	bin/env
OLDCONFIG_FILE2=	util/lg/lg.conf
NEWERCONFIG_FILES1=	etc/rancid.conf
NEWERCONFIG_FILES2=	etc/lg.conf
NEWCONFIG_FILES=	rancid.conf lg.conf

OPTIONS_DEFINE=		SVN
OPTIONS_DEFAULT=	

SVN_DESC=		Use Subversion instead of CVS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
CONFIGURE_ARGS+=	--with-svn
BUILD_DEPENDS+=		svn:${PORTSDIR}/devel/subversion
.else
CONFIGURE_ARGS+=	--without-svn
.endif

pre-everything::
	@ ${ECHO} "Make sure your rancid repository is quiet before upgrading; disable rancid cron jobs"

post-install:
	${LN} -s ${PREFIX}/libexec/${PORTNAME}/rancid-cvs ${PREFIX}/bin
	${LN} -s ${PREFIX}/libexec/${PORTNAME}/rancid-run ${PREFIX}/bin
.if !defined(BATCH)
	@ ${ECHO}
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO}
.endif
.for file in ${NEWCONFIG_FILES}
	@ if [ -f ${PREFIX}/etc/${PORTNAME}/${file} ] ; then \
	${ECHO} "WARNING: *** new ${file} file is installed as ${PREFIX}/rancid/${file}.sample"; \
	${ECHO} "       : *** review ${file}.sample for new/deprecated switches or install in place ${file}";  \
	fi
.endfor
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${NEWERCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${NEWERCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE1} -o \
	-f ${PREFIX}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${PREFIX}/var/${PORTNAME}/ "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} -o \
	-f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${PREFIX}/rancid/var "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

.include <bsd.port.mk>
