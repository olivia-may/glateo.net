mod_vortaro.la: mod_vortaro.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_vortaro.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_vortaro.la
