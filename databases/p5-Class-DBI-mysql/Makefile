# Created by: andrew@scoop.co.nz
# $FreeBSD$

PORTNAME=	Class-DBI-mysql
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensions to Class::DBI for MySQL

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::mysql.3

.include <bsd.port.mk>
