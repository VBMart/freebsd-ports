# New ports collection makefile for:	Math-SymbolicX-Inline
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-Inline
PORTVERSION=	1.11
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inlined Math::Symbolic functions

BUILD_DEPENDS=	p5-Math-Symbolic>=0:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Math-Symbolic-Custom-Contains>=0:${PORTSDIR}/math/p5-Math-Symbolic-Custom-Contains
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::Inline.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
