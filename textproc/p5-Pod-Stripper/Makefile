# New ports collection makefile for:	Pod-Stripper
# Date created:	   18 November 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Pod-Stripper
PORTVERSION=	0.22
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Strip all pod, and output what's left

PERL_CONFIGURE=	yes

MAN1=		podstrip.1
MAN3=		Pod::Stripper.3

post-patch:
	@${FIND} ${WRKSRC} -type f|${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//;'

.include <bsd.port.mk>
