# New ports collection makefile for:	p5-Net-Google-Code
# Date created:				2010-08-26
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Code
PORTVERSION=	0.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple client library for Google code

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-Mock-LWP>=0:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Mock-LWP>=0:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-XML-FeedPP>=0:${PORTSDIR}/textproc/p5-XML-FeedPP

PERL_CONFIGURE=	yes

MAN3=		Net::Google::Code.3 \
		Net::Google::Code::AtomParser.3 \
		Net::Google::Code::DateTime.3 \
		Net::Google::Code::Download.3 \
		Net::Google::Code::Issue.3 \
		Net::Google::Code::Issue::Attachment.3 \
		Net::Google::Code::Issue::Base.3 \
		Net::Google::Code::Issue::Comment.3 \
		Net::Google::Code::Issue::Search.3 \
		Net::Google::Code::Issue::Util.3 \
		Net::Google::Code::Role::Authentication.3 \
		Net::Google::Code::Role::Fetchable.3 \
		Net::Google::Code::Role::HTMLTree.3 \
		Net::Google::Code::Role::Pageable.3 \
		Net::Google::Code::Role::Predefined.3 \
		Net::Google::Code::Role::URL.3 \
		Net::Google::Code::TypicalRoles.3 \
		Net::Google::Code::Wiki.3 \
		Net::Google::Code::Wiki::Comment.3

.include <bsd.port.mk>
