# New ports collection makefile for:	Validation::Class
# Date created:		27 Jul 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Validation-Class
PORTVERSION=	7.86
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for centralized input validation for any application

RUN_DEPENDS=	\
	p5-Class-Forward>=0.04:${PORTSDIR}/devel/p5-Class-Forward \
	p5-Hash-Flatten>0:${PORTSDIR}/devel/p5-Hash-Flatten \
	p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
	p5-Module-Find>0:${PORTSDIR}/devel/p5-Module-Find \
	p5-Module-Runtime>0:${PORTSDIR}/devel/p5-Module-Runtime
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers

PERL_CONFIGURE=	yes

MAN3=	\
	Validation::Class.3 \
	Validation::Class::Backwards.3 \
	Validation::Class::Collection.3 \
	Validation::Class::Errors.3 \
	Validation::Class::Exporter.3 \
	Validation::Class::Field.3 \
	Validation::Class::Fields.3 \
	Validation::Class::Intro.3 \
	Validation::Class::Params.3 \
	Validation::Class::Prototype.3 \
	Validation::Class::Relatives.3

.include <bsd.port.mk>
