# New ports collection makefile for:	p5-IMDB-Film
# Date created:		2006-08-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IMDB-Film
PORTVERSION=	0.52
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEPANOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO Perl interface to the movies database IMDB

RUN_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-HTML-Parser>=2.28:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Text-Unidecode>=0:${PORTSDIR}/converters/p5-Text-Unidecode \
		p5-libwww>=1.41:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IMDB::BaseClass.3 IMDB::Film.3 IMDB::Persons.3

.include <bsd.port.mk>
