# $FreeBSD$

PORTNAME=	Data-Util
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for utilities for data and data types

RUN_DEPENDS=	\
	p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-Hash-Util-FieldHash-Compat>0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS} \
	p5-ExtUtils-CBuilder>0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Scope-Guard>=0.20:${PORTSDIR}/devel/p5-Scope-Guard

PERL_CONFIGURE=	yes

MAN3=		Data::Util.3 \
		Data::Util::Curry.3 \
		Data::Util::Error.3 \
		Data::Util::JA.3 \
		Data::Util::PurePerl.3

.include <bsd.port.mk>
