#ifndef __quaternion_H__
#define __quaternion_H__


typedef struct s_complexe * Complexe;
typedef struct s_imaginaire * Imaginaire;
typedef struct s_quaternion * Quaternion;

Quaternion quaternion(float , float , float , float );
Imaginaire Im(Quaternion );
float Re(Quaternion);
float norme(Quaternion);
Quaternion conjugue(Quaternion);
Quaternion inverse(Quaternion);
void affiche(Quaternion);
#endif