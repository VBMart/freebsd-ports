# $FreeBSD$

PORTNAME=	labyrinth
PORTVERSION=	0.5
CATEGORIES=	deskutils python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Mind-mapping tool for GNOME

RUN_DEPENDS+=	f2py:${PORTSDIR}/math/py-numpy

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt
USE_GNOME=	pygnome2 gnomedesktop gnomehack
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
