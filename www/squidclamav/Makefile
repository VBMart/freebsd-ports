# New ports collection makefile for:	squidclamav
# Date created:				15 August 2012
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD: ports/www/squidclamav/Makefile,v 1.1 2012/08/15 01:41:41 mm Exp $
#

PORTNAME=	squidclamav
PORTVERSION=	6.9
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Clamav c-icap service and redirector for Squid

LICENSE=	GPLv3

LIB_DEPENDS+=	icapapi:${PORTSDIR}/www/c-icap

GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_STRNSTR

MAN1=		squidclamav.1

CONFIGURE_ARGS+=	--enable-static \
			--sysconfdir="${PREFIX}/etc/c-icap" \
			--with-c-icap=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|CFGDIR=.*|CFGDIR="${PREFIX}/etc/c-icap"|g' \
		${WRKSRC}/configure.in ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/squidclamav.conf|${PREFIX}/etc/c\\-icap/squidclamav.conf|g' \
		${WRKSRC}/doc/squidclamav.1

.include <bsd.port.mk>
