TARGET   = RemoteJoyLite.exe

MAIN_OBJ = WinMain.o RemoteJoyLite.res RemoteJoyLite.o Direct3D.o DirectInput.o DebugFont.o FontData_5x5.o Log.o Deleter.o
CAPT_OBJ = Bitmap.o Movie.o Wave.o Macro.o
CONF_OBJ = Setting.o Setting_Joy.o Setting_Key.o Setting_Etc.o Setting_Filt.o Setting_Capt.o Setting_PSP.o Setting_Macro.o
FILTER_OBJ = ImageFilterNearest.o ImageFilterBilinear.o ImageFilterPixelShaderBase.o ImageFilterSpline36.o Spline36.o ImageFilterLanczos4.o lanczos4.o
DXERR_OBJ = /DxErr/src/dxerr.o

OBJS     = $(MAIN_OBJ) $(CAPT_OBJ) $(CONF_OBJ) $(FILTER_OBJ) $(DXERR_OBJ)
LIBS     = -ld3d9 -ldinput -ldxguid -lwinmm -lvfw32 -lusb0_$(ARCH) -Wl,-Bstatic -lpthread -static-libgcc -static-libstdc++
#LANGUAGE =  LANG_JA
#LANGUAGE =  LANG_EN
CFLAGS   = -O2 -Wall -g -DWINVER=0x0500 -DUNICODE -DLANGUAGE=$(LANGUAGE)
LDFLAGS  = -L/usr/local/lib -L./ -mwindows
RCFLAGS  = -O coff

.SUFFIXES: .cpp .c .rc .res .o

$(TARGET) : $(OBJS)
	$(CPPC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

.cpp.o:
	$(CPPC) $(CFLAGS) -c $*.cpp

.rc.res:
	$(WINDRES) $(RCFLAGS) $*.rc -o $*.res

clean: 
	@rm -rf *.exe *.o *.res *~

strip:
	strip $(TARGET)

depend: $(OBJS:.o=.cpp)
	-@rm depend.inc
	-@for i in $^; do\
		gcc $(CFLAGS) -MM $$i >> depend.inc;\
	done

-include depend.inc
