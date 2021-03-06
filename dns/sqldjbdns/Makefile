# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	sqldjbdns
PORTVERSION=	0.74
CATEGORIES=	dns
MASTER_SITES=	http://home.tiscali.cz:8080/~cz210552/distfiles/ \
		http://home.tiscali.cz/~cz210552/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJB DNS server with PostgreSQL backend

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

DJ_PORT?=	${PORTSDIR}/dns/djbdns
BUILD_DEPENDS=	${NONEXISTENT}:${DJ_PORT}:extract
RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools

USE_PGSQL=	YES

PORTDOCS=	ANNOUNCEMENT STATUS pgsqldns.html NEWS TODO README \
		pgsqldns-conf.html sqldns.html pgsqldns-schema.html
DJ_SRC=		`cd ${DJ_PORT} && make -V WRKSRC`
ALL_TARGET=	default
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/dnsbench bin/pgsqldns bin/pgsqldns-conf bin/pgsqldnscache \
		share/examples/${PORTNAME}/create.sql
PLIST_DIRS=	share/examples/${PORTNAME}

post-configure:
		${CP} -R ${DJ_SRC} ${WRKSRC}/djbdns-1.05
		${PATCH} < ${WRKSRC}/djbdns-1.05.patch -d ${WRKSRC}/djbdns-1.05
		${MV} ${WRKSRC}/sqldns-schema.html ${WRKSRC}/pgsqldns-schema.html

post-install:
		${MKDIR} ${EXAMPLESDIR}
		${INSTALL_DATA}  ${WRKSRC}/create.sql ${EXAMPLESDIR}
.ifndef NOPORTDOCS
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
