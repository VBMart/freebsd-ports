# New ports collection makefile for:	p5-WWW-Hotmail
# Date created:		2006-07-20
# Whom:			Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Hotmail
PORTVERSION=	0.10
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	This module simplifies access to hotmail

BUILD_DEPENDS=	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Mail-Audit>=0:${PORTSDIR}/mail/p5-Mail-Audit
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Hotmail.3

.include <bsd.port.mk>
