# New ports collection makefile for:	dbd_sqlite for DBD-for-Ruby
# Date created:		15 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sqlite
PORTVERSION=	0.1.2
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-dbi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	dbd-sqlite-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SQLite driver for DBI-for-Ruby

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${PORTSDIR}/databases/ruby-dbi

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

.include <bsd.port.mk>
