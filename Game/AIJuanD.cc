#include "Player.hh"
#include <stdlib.h>
#include <utility>
#include <unistd.h>


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME JuanD


// DISCLAIMER: The following Demo player is *not* meant to do anything
// sensiLBe. It is provided just to illustrate how to use the API.
// Please use AINull.cc as a template for your player.


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and atributes for your player can be defined here.
   */

  // Esto tiene sentido, ves a la función dijkstra
  struct Node{
    Pos pos;
    int weight;
    Pos ancient;
  };

  // Cosas de la cola de prioridades
  struct CompareNodes {
    bool operator()(Node const& a, Node const& b){
      if(a.weight == b.weight){
        if(a.pos.i == b.pos.i) return a.pos.j < b.pos.j;
        else return a.pos.i < b.pos.i;
      }
      else return a.weight < b.weight;
    }
  };

/*  // Cosas de priority queues con nodos
  bool greater(Node a, Node b){
    if(a.weight == b.weight){
      if(a.pos.i == b.pos.i) return a.pos.j < b.pos.j;
      else return a.pos.i < b.pos.i;
    }
    else return a.weight < b.weight;
  }
*/
  typedef vector<int> VI; // Vector de enteros del
  typedef vector<vector<bool>> Matrix; // Matriz
  typedef vector<Pos> VPos; // Vector de posiciones
  typedef priority_queue<Node, vector<Node>, CompareNodes > Pqueue; // Cola de prioridades de Nodos


// ******************FUNCIONES MIAS DE MI UNIDAD****************** //


  // **********FUNCIONES GENERALES********** //

  /* FUNCIÓN QUE CALCULA SI SE PUEDE OCUPAR LA CASILLA */
  bool puede_ocuparse(Pos pos) {
    //cerr << "Entrando en puede_ocuparse..." << endl;
    if(pos_ok(pos)){
      Cell ahora = cell(pos);
      if(ahora.type == Outside or ahora.type == Cave){
        //cerr << "puede_ocuparse funciona bien" << endl;
        if(ahora.id != -1 and unit(ahora.id).player != me()) return true;
        if(ahora.id == -1) return true;
      }
    }
    //cerr << "puede_ocuparse funciona bien" << endl;
    return false;
  }

  /* FUNCIÓN QUE HUYE DEL ENEMIGO */
  void muevete_lejos(Unit my_D, Pos pos_strngr) {
    //cerr << "Entrando en muevete_lejos..." << endl;
    int i = (my_D.pos).i - pos_strngr.i;
    int j = (my_D.pos).j - pos_strngr.j;
    if(i>0){
      // i>0 ^ j>0
      if(j>0){
        if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else command(my_D.id, None);
      }
      // i>0 ^ j<0
      else if(j<0){
        if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else command(my_D.id, None);
      }
      // i>0 ^ j=0
      else{
        if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else command(my_D.id, None);
      }
    }

    else if(i<0){
      // i<0 ^ j>0
      if(j>0){
        if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else command(my_D.id, None);
      }
      // i<0 ^ j<0
      else if(j<0){
        if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else command(my_D.id, None);
      }
      // i<0 ^ j=0
      else{
        if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else command(my_D.id, None);
      }
    }
    else{
      // i=0 ^ j>0
      if(j>0){
        if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else command(my_D.id, None);
      }
      // i=0 ^ j<0
      else if(j<0){
        if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else command(my_D.id, None);
      }
      // i=0 ^ j=0, el enemigo soy yo
      else{
        if(puede_ocuparse(my_D.pos + Bottom)) command(my_D.id, Bottom);
        else if(puede_ocuparse(my_D.pos + BR)) command(my_D.id, BR);
        else if(puede_ocuparse(my_D.pos + Right)) command(my_D.id, Right);
        else if(puede_ocuparse(my_D.pos + RT)) command(my_D.id, RT);
        else if(puede_ocuparse(my_D.pos + Top)) command(my_D.id, Top);
        else if(puede_ocuparse(my_D.pos + TL)) command(my_D.id, TL);
        else if(puede_ocuparse(my_D.pos + Left)) command(my_D.id, Left);
        else if(puede_ocuparse(my_D.pos + LB)) command(my_D.id, LB);
        else command(my_D.id, None);
      }
    }
    //cerr << "muevete_lejos funciona bien" << endl;
  }

  /* FUNCIÓN QUE DEVUELVE 5 SI LA POSICIÓN ES UNA ROCA */
  int es_roca(Pos pos){
    //cerr << "Entrando en es_roca..." << endl;
    if(pos_ok(pos) and cell(pos).type == Rock){
      //cerr << "es_roca funciona bien" << endl;
      return 5;
    }
    //cerr << "es_roca funciona bien" << endl;
    return 0;
  }

  /* FUNCIÓN QUE DEVUELVE SI LA POSICIÓN HA SIDO VISITADA EN LA MATRIZ */
  bool visitado(Matrix m, Pos pos) {
    //cerr << "Entrando en visitado..." << endl;
    int i = pos.i;
    int j = pos.j;
    if(i >= 0  and i < m.size() and j >= 0 and j < m[0].size()){
      //cerr << "visitado funciona bien" << endl;
      return m[pos.i][pos.j];
    }
    //cerr << "visitado funciona bien" << endl;
    return true;
  }

  /* FUNCIÓN QUE DEVUELVE SI LA POSICIÓN EXISTE EN LA MATRIZ */
  bool matrix_ok(Matrix m, int i, int j){
    //cerr << "Entrando en matrix_ok..." << endl;
    if(i < 0 or j < 0 or i >= m.size() or j >= m[0].size()){
      //cerr << "matrix_ok funciona bien" << endl;
      return false;
    }
    //cerr << "matrix_ok funciona bien" << endl;
    return true;
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// IMPRIME MATRIZ
/*void imprime_matriz(Matrix m){
  for(int i = 0; i < m.size(); ++i){
    for(int j = 0; j < m[0].size(); ++j) cerr << m[i][j] << " ";
    cerr << endl;
  }
  cerr << endl;
  //sleep(1);
}
*/
  /* FUNCIÓN QUE DEVUELVE LA DISTANCIA MÍNIMA Y EL SIGUIENTE PASO A DAR */
  // Para la función necesitamos crear un tipo de dato especial que se llamará Node (creado al principio del programa)
  // Definimos la función
  pair<int, Pos> dijkstra(Pqueue node_store, Pos goal, int square) {
    //cerr << "Entrando en dijkstra..." << endl;
    Node actual, aux;
    Pos base = node_store.top().pos;
    // Para actualizar la matriz
    base.i = node_store.top().pos.i - square/2;
    base.j = node_store.top().pos.j - square/2;
    Matrix visitados(square, vector<bool>(square, false));
    // Mientras hayan posiciones posibles, sigue buscando
    while(node_store.size()){
      // Guardo el actual nodo
      actual = node_store.top();
      node_store.pop();
      // Devuelvo el nodo si he encontrado el goal
      Pos comparador;
      if(actual.pos+base == goal){
        //cerr << "dijkstra funciona bien" << endl;
        return make_pair(actual.weight, actual.ancient);
      }
      else{
        // No ha sido visitado todavía
        if(!visitado(visitados, actual.pos)){
          aux = actual;
          // Miramos todas las posibles posiciones y las guardamos en la cola de prioridades
          if((puede_ocuparse(actual.pos+base+Bottom) or es_roca(actual.pos+base+Bottom)) and !visitado(visitados, actual.pos+Bottom)){
            aux.pos+=Bottom;
            aux.weight += (1 + es_roca(actual.pos+base+Bottom));
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+BR) or es_roca(actual.pos+base+BR)) and !visitado(visitados, actual.pos+BR)) {
            aux.pos+=BR;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+BR);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+Right) or es_roca(actual.pos+base+Right)) and !visitado(visitados, actual.pos+Right)) {
            aux.pos+=Right;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+Right);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+RT) or es_roca(actual.pos+base+RT)) and !visitado(visitados, actual.pos+RT)) {
            aux.pos+=RT;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+RT);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+Top) or es_roca(actual.pos+base+Top)) and !visitado(visitados, actual.pos+Top)) {
            aux.pos+=Top;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+Top);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+TL) or es_roca(actual.pos+base+TL)) and !visitado(visitados, actual.pos+TL)) {
            aux.pos+=TL;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+TL);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+Left) or es_roca(actual.pos+base+Left)) and !visitado(visitados, actual.pos+Left)) {
            aux.pos+=Left;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+Left);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if((puede_ocuparse(actual.pos+base+LB) or es_roca(actual.pos+base+LB)) and !visitado(visitados, actual.pos+LB)) {
            aux.pos+=LB;
            aux.weight = aux.weight + 1 + es_roca(actual.pos+base+LB);
            if(aux.ancient == Pos(-1, -1)) aux.ancient = aux.pos+base;
            else aux.ancient = actual.ancient;
            node_store.push(aux);
          }
          if(matrix_ok(visitados, actual.pos.i, actual.pos.j)) visitados[actual.pos.i][actual.pos.j] = true;
          //imprime_matriz(visitados);
        }
      }
    }
    return make_pair(-1, Pos(-1, -1));
    //cerr << "Te saliste wey" << endl;
  }

  /* FUNCIÓN QUE DEVUELVE LA DIRECCIÓN QUE MOVER PARA LLEGAR A LA POSICIÓN ADYACENTE */
  // Siempre la posición adyacente es una distinta a base
  Dir adyac(Pos base, Pos adjacent) {
    //cerr << "Entrando a adyac..." << endl;
    if(base+Bottom == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return Bottom;
    }
    if(base+BR == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return BR;
    }
    if(base+Right == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return Right;
    }
    if(base+RT == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return RT;
    }
    if(base+Top == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return Top;
    }
    if(base+TL == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return TL;
    }
    if(base+Left == adjacent){
      //cerr << "adyac funciona bien" << endl;
      return Left;
    }
    //cerr << "adyac funciona bien" << endl;
    return LB;
  }


  // **********BALROG Y TROLLS********** //

  /* FUNCIÓN QUE DEVUELVE LA POSICIÓN DEL BALROG O ALGÚN TROLL SI ESTÁN CERCA */
  Pos balrog_troll(Pos pos, int square) {
    int half = square/2;
    // Mira si el Balrog está cerca
    Pos pos_B = unit(balrog_id()).pos;
    if(abs(pos_B.i - pos.i) <= half or abs(pos_B.j - pos.j) <= half) return pos_B;

    // Mira si algún troll está cerca
    VI id_trolls = trolls();
    Pos pos_T;
    for(int i = 0; i < id_trolls.size(); ++i) {
      pos_T = unit(id_trolls[i]).pos;
      if(abs(pos_T.i - pos.i) < half or abs(pos_T.j - pos.j) < half) return pos_T;
    }
    return Pos(-1, -1);
  }


  // **********ENEMIGO O TESORO********** //

  /* FUNCIÓN QUE DEVUELVE SI HAY UN ENEMIGO O TESORO */
  int hay_algo(Pos pos){
    //cerr << "Entrando en hay_algo..." << endl;

    Cell Zelda = cell(pos);
    //cerr << pos.i << ' ' << pos.j << ' ' << Zelda.treasure << ' ' << unit(Zelda.id).player << endl;
    // Si hay tesoro devuelve 1
    if(Zelda.id == -1){
      //cerr << "hay_algo funciona bien" << endl;
      return Zelda.treasure;
    }
    // Si hay enemigo devuelve 2
    if(unit(Zelda.id).player != me() and Zelda.id != balrog_id()){
      //cerr << "hay_algo funciona bien" << endl;
      return 2;
    }
    // No hay nada
    //cerr << "hay_algo funciona bien" << endl;
    return 0;
  }

  /* FUNCIÓN QUE DEVUELVE EL ID DE UN ENEMIGO O DE UN TESORO SI HAY (en ese orden de preferencia) */
  pair<Pos, int> cerca_enemigo_tesoro(Pos start, int square) {
    // Inicializamos las variaLBes para calcular el enemigo más cercano
    //cerr << "Entrando en cerca_enemigo_tesoro..." << endl;
    int min = -1;
    Pos goal;
    pair<Pos, int> resultado;
    resultado.first = Pos(-1, -1);
    resultado.second = 0;
    // Bucle para ver cada casilla
    int half = square/2;
    for(int i = -1*half; i <= half; ++i){
      for(int j = -1*half; j <= half; ++j){
        if(i == 0 and j == 0) continue;
        goal = start + Pos(i, j);
        // Miro si puede es una casilla que se puede ocupar
        if(puede_ocuparse(goal)){
          // Miro si hay algún enemigo o tesoro
          int enemigo_tesoro = hay_algo(goal);
          //cerr << "salgo del hay_algo" << endl;
          if(enemigo_tesoro){
            // Calculo la distancia mínima hasta la posición y miro si es la mínima encontrada hasta el momento
            Pqueue aux;
            Node first; first.pos.i = first.pos.j = square/2; first.weight = 0; first.ancient = Pos(-1, -1);
            aux.push(first);
            //cerr << "Predijks" << endl;
            pair<int, Pos> dist = dijkstra(aux, goal, square);
            //cerr << "Postdijks" << endl;
            if(min == -1 or dist.first < min and dist.second != Pos(-1, -1)){
              // Guardo la distancia mínima
              min = dist.first;
              // Guardo si es un enemigo o tesoro y la siguiente posición que se debe mover para llegar al enemigo/tesoro
              resultado = make_pair(dist.second, enemigo_tesoro);

            }
          }
        }
      }
    }
    //cerr << "cerca_enemigo_tesoro funciona bien" << endl;
    return resultado;
  }

  /* FUNCIÓN QUE DECIDE SI ATACAR O HUIR */
  void en_garde(Unit my_D, Pos next) {
    //cerr << "Entrando en en_garde" << endl;
    /*if(my_D.health >= 50)*/ command(my_D.id, adyac(my_D.pos, next));
    //else muevete_lejos(my_D, next);
    //cerr << "en_garde funciona bien" << endl;
  }


  // **********TERRITORIO NACIONAL********** //

  /* FUNCIÓN QUE DEVUELVE LA DIRECCIÓN DE LA CASILLA QUE NO SE POSEE O NINGUNA DIRECCIÓN */
  Dir no_owner(Pos pos, int square) {
    //cerr << "Entrando en no_owner" << endl;
    if(puede_ocuparse(pos+Bottom) and cell(pos+Bottom).type != Outside and cell(pos+Bottom).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return Bottom;
    }
    if(puede_ocuparse(pos+BR) and cell(pos+BR).type != Outside and cell(pos+BR).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return BR;
    }
    if(puede_ocuparse(pos+Right) and cell(pos+Right).type != Outside and cell(pos+Right).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return Right;
    }
    if(puede_ocuparse(pos+RT) and cell(pos+RT).type != Outside and cell(pos+RT).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return RT;
    }
    if(puede_ocuparse(pos+Top) and cell(pos+Top).type != Outside and cell(pos+Top).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return Top;
    }
    if(puede_ocuparse(pos+TL) and cell(pos+TL).type != Outside and cell(pos+TL).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return TL;
    }
    if(puede_ocuparse(pos+Left) and cell(pos+Left).type != Outside and cell(pos+Left).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return Left;
    }
    if(puede_ocuparse(pos+LB) and cell(pos+LB).type != Outside and cell(pos+LB).owner != me()){
      //cerr << "no_owner funciona bien" << endl;
      return LB;
    }
    //cerr << "no_owner funciona bien" << endl;
    return None;
  }



// ******************EMPIEZA EL PROGRAMA PRINCIPAL****************** //

  /* Función de movimiento de los dwarves */
  void move_dwarves() {
    // Guardamos al ID de mis dwarves
    VI Dwarves = dwarves(me());
    // Bucle para trabajar con cada dwarf
    for(int i = 0; i < Dwarves.size(); ++i){
      // Guardamos el id del dwarf que tratamos en esta iteración
      int id = Dwarves[i];
      // Recogemos la posición del dwarf
      Unit my_D = unit(id);

      // Nos movemos si tenemos cerca el Balrog o algún troll en un 7x7
      Pos pos_stronger = balrog_troll(my_D.pos, 7);
      // Nos movemos lejos si tenemos cerca el Balrog o algún troll
      if(pos_stronger != Pos(-1, -1)){
        muevete_lejos(my_D, pos_stronger);
      }
      // No tenemos cerca ni el Balrog ni algún troll
      else{
        // Miramos si tenemos enemigo cerca en un 10x10
        pair<Pos, int> is_EorT = cerca_enemigo_tesoro(my_D.pos, 11);
        if(is_EorT.second == 2){
          cerr << my_D.pos.i << ' ' << my_D.pos.j << endl;
          cerr << is_EorT.first.i << ' ' << is_EorT.first.j << endl;
          en_garde(my_D, is_EorT.first);
        }
        // No tenemos ningún enemigo cerca
        else{
          // Miramos si tenemos una casilla sin poseer adyacente
          Dir d = no_owner(my_D.pos, 3);
          // Miramos si hay algún tesoro cerca en el 10x10 anterior
          if(is_EorT.second){
            command(my_D.id, adyac(my_D.pos, is_EorT.first));
          }
          else if(d != None) command(my_D.id, d);
          // No hay ninguna preferencia, por lo tanto muevete random
          else muevete_lejos(my_D, my_D.pos);
        }
      }
    }
  }

  void move_wizards() {
    VI Wizards = wizards(me());
    for(int i = 0; i < Wizards.size(); ++i) command(Wizards[i], None);
  }


  /**
   * Play method, invoked once per each round.
   */
  void play () {
    move_dwarves();
    move_wizards();
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
