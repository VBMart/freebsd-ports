# New ports collection makefile for:	p5-Net-CascadeCopy
# Date created:		2010-10-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-CascadeCopy
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Rapidly propagate files to many servers in multiple locations

BUILD_DEPENDS=	p5-Class-Std-Utils>=v0.0.0:${PORTSDIR}/devel/p5-Class-Std-Utils \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Proc-Queue>=0:${PORTSDIR}/devel/p5-Proc-Queue
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences

PERL_CONFIGURE=	yes

MAN3=		Net::CascadeCopy.3

.include <bsd.port.mk>
