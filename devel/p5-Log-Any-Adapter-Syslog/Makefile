# New ports collection makefile for:	devel/p5-Log-Any-Adapter-Syslog
# Date created:				10 Oct 2010
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Log-Any-Adapter-Syslog
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Send Log::Any logs to syslog

RUN_DEPENDS=	p5-Log-Any-Adapter>=0:${PORTSDIR}/devel/p5-Log-Any-Adapter \
		p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule

PERL_CONFIGURE=	yes

MAN3=	Log::Any::Adapter::Syslog.3

.include <bsd.port.mk>
