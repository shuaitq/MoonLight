PROJECT = MoonLight
CPP = g++
CPPFLAGS = -std=c++11 -Wall
ifdef DEBUG
CPPFLAGS += -g
else
CPPFLAGS += -O2
endif
SRCS = MoonLight.cpp \
	BRDF/Diffuse.cpp BRDF/Glossy.cpp BRDF/Specular.cpp \
	Camera/FisheyeCamera.cpp Camera/OrthographicCamera.cpp Camera/PerspectiveCamera.cpp \
	Core/World.cpp \
	ImageFormat/PPM.cpp \
	Material/Matte.cpp Material/Mirror.cpp Material/Glass.cpp \
	Sampler/Jittered.cpp \
	ToneMapping/ACESMapping.cpp ToneMapping/GammaCorrection.cpp ToneMapping/Standardization.cpp \
	Tracer/Whitted.cpp \
	Utility/Rand.cpp

OBJS = $(SRCS:.cpp=.o)

$(PROJECT): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)