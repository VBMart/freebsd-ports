# $FreeBSD$

PORTNAME=	Test-TCP
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for testing TCP program

RUN_DEPENDS=	\
	p5-Test-SharedFork>=0.19:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS:=	${RUN_DEPENDS}
# XXX: test t/05_sigint.t fails.  Check it later.

PERL_CONFIGURE=	yes

MAN3=	Test::TCP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
