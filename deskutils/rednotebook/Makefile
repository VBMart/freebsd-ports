# Created by: Hon-Yu Lawrence Cheung (cheunghonyu@gmail.com)
# $FreeBSD$

PORTNAME=	rednotebook
PORTVERSION=	1.6.1
CATEGORIES=	deskutils python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rednotebook
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cheunghonyu@gmail.com
COMMENT=	Modern journal written in Python

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>0:${PORTSDIR}/www/py-webkitgtk \
		${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py-chardet

USE_GETTEXT=	yes

INSTALLS_ICONS=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
