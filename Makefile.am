ACLOCAL_AMFLAGS = -I m4
MAINTAINERCLEANFILES = Makefile.in aclocal.m4 config.guess config.h.in \
		       config.sub configure depcomp install-sh ltmain.sh \
		       missing module.desktop config.rpath mkinstalldirs

SUBDIRS = src

if HAVE_PO

SUBDIRS += po

endif

EDJE_FLAGS = -v \
	     -id $(top_srcdir)/images

filesdir = $(datadir)
files_DATA = module.desktop e-module-elivehelpers.edj elivehelpers.edj

EXTRA_DIST = module.desktop.in \
	     e_modules-elivehelpers.spec.in \
	     e-module-elivehelpers.edc \
	     images/module_icon.png \
		 elivehelpers.edc \
		 images/gadcon_logo.png

e-module-elivehelpers.edj: Makefile e-module-elivehelpers.edc images/module_icon.png
elivehelpers.edj: Makefile elivehelpers.edc  images/gadcon_logo.png

%.edj:  %.edc
	$(EDJE_CC) $(EDJE_FLAGS) $< $@

clean-local:
	 rm -rf *.edj module.desktop e_modules-elivehelpers.spec *~
uninstall:
	 rm -rf $(DESTDIR)$(datadir)
