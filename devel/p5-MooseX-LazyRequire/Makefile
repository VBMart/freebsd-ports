# New ports collection makefile for:	MooseX-LazyRequire
# Date created:	   17 Aug 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-LazyRequire
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Required attributes which fail only when trying to use them

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-aliased>=0.30:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckDeps>=0.002:${PORTSDIR}/devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		MooseX::LazyRequire.3 \
		MooseX::LazyRequire::Meta::Attribute::Trait::LazyRequire.3

.include <bsd.port.mk>
