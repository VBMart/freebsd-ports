# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-LinearCombination
PORTVERSION=	0.03
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sum of variables with a numerical coefficient

DEPRECATED=	Depends on the expired p5-Class-Field
EXPIRATION_DATE=	2012-11-27

BUILD_DEPENDS=	p5-Class-Fields>=0:${PORTSDIR}/devel/p5-Class-Fields \
		p5-Math-SimpleVariable>=0:${PORTSDIR}/math/p5-Math-SimpleVariable
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::LinearCombination.3

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
		's!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+!my !;'

.include <bsd.port.mk>
