# $FreeBSD$

PORTNAME=	pkg_jail
PORTVERSION=	1.71
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Manage your own package jail

NO_BUILD=	yes

PLIST_FILES=	bin/pkg_jail bin/pkg_update
PORTDOCS=	README
MAN1=		pkg_jail.1 pkg_update.1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_jail ${FILESDIR}/pkg_update ${PREFIX}/bin/
	${INSTALL_MAN} ${FILESDIR}/pkg_jail.1 ${FILESDIR}/pkg_update.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${DOCSDIR}/
.endif

install-ports:
	-${MKDIR} ${PORTSDIR}/local/update/data
	${LN} -s ${FILESDIR}/README ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_update ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_jail ${PORTSDIR}/local/update/

.include <bsd.port.mk>
