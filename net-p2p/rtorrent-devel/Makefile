# New ports collection makefile for:	rtorrent-devel
# Date created:				May 17 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent-devel
PORTVERSION=	0.9.1
PORTREVISION=	0
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	az@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

BUILD_DEPENDS=	libtorrent-devel=0.13.1_1:${PORTSDIR}/net-p2p/libtorrent-devel
RUN_DEPENDS=	libtorrent-devel=0.13.1_1:${PORTSDIR}/net-p2p/libtorrent-devel

MASTERDIR=	${.CURDIR}/../rtorrent
PATCHDIR=	${.CURDIR}/files/
DISTINFO_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${MASTERDIR}/pkg-descr

CONFLICTS=	rtorrent-[0-9]*

USE_GCC=	4.2+

.include "${MASTERDIR}/Makefile"
