#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;
  struct matrix * polygons;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  polygons = new_matrix(4, 4);

  color color;
  color.red = MAX_COLOR;
  color.green = 0;
  color.blue = 0;

  clear_screen(s);
    
  /* print_matrix( make_bezier() ); */
  /* printf("\n"); */
  /* print_matrix( make_hermite() ); */

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "face_script", transform, edges, s );



  /* add_polygon(polygons,100.0,100.0,0.0, */
  /* 	      200.0,100.0,0.0, */
  /* 	      200.0,200.0,0.0); */



  /* matrix_mult(make_rotX(30), polygons); */
  /* matrix_mult(make_rotY(30), polygons); */
  /* matrix_mult(make_translate(100,100,0), polygons); */

  /* ident(edges); */
  
  add_box(polygons,-80,-120,0,75,75,75);
  /* add_box(polygons, -200, 200, 200, 400, 400, 400); */
  /* add_sphere(polygons, 0, 0, 0, 50, 0.05); */
  /* add_torus(polygons,0,0,0,150,100,0.05); */
  /* matrix_mult(make_translate(-250,-250,0), polygons); */
  /* add_box(polygons,275,175,0,40,50,50); */

  matrix_mult(make_rotX(30), polygons);
  matrix_mult(make_rotY(-20), polygons);
  matrix_mult(make_translate(250,250,0), polygons);
  
  /* print_matrix(edges); */
  /* print_matrix(polygons); */

  /* matrix_mult(make_rotX(30), polygons); */
  /* matrix_mult(make_rotY(30), polygons); */

  /* draw_lines(edges,s,color); */
  draw_polygons(polygons, s, color);

  /* print_matrix(polygons); */
  
  display(s);


  save_extension(s, "thing1.png");
  
  free_matrix(polygons);
  free_matrix( edges );
  free_matrix( transform );

}  
