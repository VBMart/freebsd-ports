# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Message
PORTVERSION=	6.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Representation of HTTP style messages

BUILD_DEPENDS=	p5-Encode-Locale>=1:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-HTML-Parser>=3.33:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Date>=6:${PORTSDIR}/www/p5-HTTP-Date \
		p5-LWP-MediaTypes>=6:${PORTSDIR}/www/p5-LWP-MediaTypes \
		p5-URI>=1.10:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-libwww-5*

PERL_CONFIGURE=	yes

MAN3=		HTTP::Config.3 \
		HTTP::Headers.3 \
		HTTP::Headers::Util.3 \
		HTTP::Message.3 \
		HTTP::Request.3 \
		HTTP::Request::Common.3 \
		HTTP::Response.3 \
		HTTP::Status.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
RUN_DEPENDS+=	p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-IO-Compress>=2.021:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=2.021:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
