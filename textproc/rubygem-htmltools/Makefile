# $FreeBSD$

PORTNAME=	htmltools
PORTVERSION=	1.10
CATEGORIES=	textproc www rubygems
MASTER_SITES=	RG
DISTNAME=	htmltools-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tools for parsing and manipulating HTML text in Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
