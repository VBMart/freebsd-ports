# New ports collection makefile for: hs-configurator
# Date created:        November 19, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	configurator
PORTVERSION=	0.2.0.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Configuration management

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10.0.2 hashable text>=0.11.1.0 unix-compat \
		unordered-containers

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
