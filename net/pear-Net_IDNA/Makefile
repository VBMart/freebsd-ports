# Created by: Michael Frey <frey@raum3.de>
# $FreeBSD$

PORTNAME=	Net_IDNA
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	net pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pear Punycode encoding and decoding package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Net
FILES=		IDNA.php \
		IDNA/php5.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
