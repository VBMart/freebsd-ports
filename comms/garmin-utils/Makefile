# Created by: Matthew Braithwaite <mab@red-bean.com>
# $FreeBSD$

PORTNAME=	garmin-utils
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	comms geography
MASTER_SITES=	ftp://ftp.snafu.org/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for Garmin GPS receivers

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

MAN1=		gardump.1 garload.1
MANCOMPRESSED=	yes
MAKE_ARGS+=	MANDIR=${MANPREFIX}/man/man
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/gardump bin/garload

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800045
MAKE_ARGS+=	GPS_SERIAL_PORT=/dev/cuad0
.else
MAKE_ARGS+=	GPS_SERIAL_PORT=/dev/cuau0
.endif

.include <bsd.port.post.mk>
