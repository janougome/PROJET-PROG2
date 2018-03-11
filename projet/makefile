
CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentÃ©e : choisissez les options que vous voulez avoir
#                    en dÃ©commentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
#CXXFLAGS += -pg                   # pour profiler
#LDFLAGS  += -pg                   # pour profiler
#CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testVecteur

Vecteur.o: Vecteur.cpp Vecteur.h

testVecteur.o: testVecteur.cpp Vecteur.h

testVecteur: testVecteur.o Vecteur.o
