# $FreeBSD$

PORTNAME=	pastebinit
PORTVERSION=	1.3.1
CATEGORIES=	misc python
MASTER_SITES=	https://launchpadlibrarian.net/106457425/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	A command line utility for pastebing

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:${PORTSDIR}/devel/py-configobj

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pastebinit

LICENSE=	GPLv2

OPTIONS_DEFINE=	PASTEBINS
PASTEBINS_DESC=	Install default pastebins
OPTIONS_DEFAULT=	PASTEBINS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPASTEBINS}
PORTDATA=	pastebin.d
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/pastebin.d|${DATADIR}/pastebin.d|' \
		${WRKSRC}/pastebinit 
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MPASTEBINS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${DATADIR})
.endif

.include <bsd.port.mk>
