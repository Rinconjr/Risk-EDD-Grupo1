#ifndef RISK_H
#define RISK_H

#include <string>
#include <vector>

void comando_inicializar();
void comando_turno();
void comando_guardar();
void comando_guardar_comprimido();
void comando_costo_conquista();
void comando_conquista_mas_barata();
void comando_ayuda();
void comando_ayuda_comandos(const std::string& comando);

#endif // RISK_H

//eof - risk.h
