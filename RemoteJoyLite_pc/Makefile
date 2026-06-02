TARGET   = RemoteJoyLite.exe
MAIN_OBJ = WinMain.obj RemoteJoyLite.res RemoteJoyLite.o Direct3D.o DirectInput.o DebugFont.o FontData_5x5.o Log.o Deleter.o
CAPT_OBJ = Bitmap.o Movie.o Wave.o Macro.o
CONF_OBJ = Setting.obj Setting_Joy.obj Setting_Key.obj Setting_Etc.obj Setting_Filt.obj Setting_Capt.obj Setting_PSP.obj Setting_Macro.obj
FILTER_OBJ = ImageFilterNearest.o ImageFilterBilinear.o ImageFilterPixelShaderBase.o ImageFilterSpline36.o Spline36.o ImageFilterLanczos4.o lanczos4.o
OBJS     = $(MAIN_OBJ) $(CAPT_OBJ) $(CONF_OBJ) $(FILTER_OBJ)
LIBS     = -ld3d9 -ldinput -ldxguid -lwinmm -lvfw32 -lusb0_$(ARCH) -Wl,-Bstatic -lpthread -static-libgcc -static-libstdc++
#LANGUAGE =  LANG_JA
LANGUAGE =  LANG_EN
CFLAGS   = -O2 -Wall -g -DWINVER=0x0500 -DUNICODE -DLANGUAGE=$(LANGUAGE)
LDFLAGS  = -L/usr/local/lib -L./ -mwindows
RCFLAGS  = -O coff

.SUFFIXES: .cpp .c .rc .res .o

$(TARGET) : $(OBJS)
	link $(LDFLAGS) $(OBJS) $(LIBS) /OUT:$(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

.cpp.o:
	$(CPPC) $(CFLAGS) -c $*.cpp

.rc.res:
	$(WINDRES) $(RCFLAGS) $*.rc

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
