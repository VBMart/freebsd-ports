# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-nox11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A user-level file synchronization tool (without x11 stuff)

CONFLICTS=	unison-[0-9]* unison-devel-[0-9]*

OPTIONS_EXCLUDE=	X11
OPTIONS_DEFAULT=	DOCS
MASTERDIR=	${.CURDIR}/../unison

.include "${MASTERDIR}/Makefile"
