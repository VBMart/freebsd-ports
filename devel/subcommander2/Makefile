# Created by: Naram Qashat
# $FreeBSD$

PORTNAME=	subcommander
PORTVERSION=	2.0.0.b5
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://subcommander.tigris.org/files/documents/1759/46766/
DISTNAME=	Subcommander-${PORTVERSION:S/.b/b/g}p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 based multiplatform subversion client, diff & merge tool

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	neon:${PORTSDIR}/www/neon29 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		svn_client-1:${PORTSDIR}/devel/subversion \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

LATEST_LINK=	subcommander2
CONFLICTS=	subcommander-1.*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.b/b/g}
USE_DOS2UNIX=	*.cpp *.h

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT4=	qt3support gui network corelib moc_build uic_build rcc_build
CONFIGURE_ARGS+=	--with-boost=${LOCALBASE}/include --with-neon=${LOCALBASE} \
			--with-subversion=${LOCALBASE} --with-qt=${LOCALBASE} \
			--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config \
			--with-openssl=${OPENSSLBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/qt4 ${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes

post-extract:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
