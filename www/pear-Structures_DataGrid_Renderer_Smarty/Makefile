# Ports collection makefile for:	pear-Structures_DataGrid_Renderer_Smarty
# Date created:				26 Jun 2008
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_Renderer_Smarty
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	www pear

MAINTAINER=	nick@foobar.org
COMMENT=	Smarty Renderer for pear-Structures_DataGrid

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty2 \
		${PEARDIR}/Structures/DataGrid/Renderer/Pager.php:${PORTSDIR}/www/pear-Structures_DataGrid_Renderer_Pager

CATEGORY=	Structures
FILES=		DataGrid/Renderer/Smarty.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
