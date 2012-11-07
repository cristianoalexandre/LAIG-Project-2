#include "Plane.h"

Plane::Plane(GLint divisions_u, GLint divisions_v)
{
	/** Defines control points */

	control_points[0][0] = -0.5;
	control_points[0][1] = 0;
	control_points[0][2] = 0.5;

	control_points[1][0] = 0.5;
	control_points[1][1] = 0;
	control_points[1][2] = 0.5;

	control_points[2][0] = 0.5;
	control_points[2][1] = 0;
	control_points[2][2] = -0.5;

	control_points[3][0] = -0.5;
	control_points[3][1] = 0;
	control_points[3][2] = -0.5;

	/** Defines texture points */
	texture_points[0][0] = 0;
	texture_points[0][1] = 0;

	texture_points[1][0] = 0;
	texture_points[1][0] = 1;

	texture_points[1][0] = 1;
	texture_points[1][0] = 0;

	texture_points[1][0] = 1;
	texture_points[1][0] = 1;

	/** Defines number of divisions */
	divisions[0] = divisions_u;
	divisions[1] = divisions_v;
}

void Plane::draw()
{
	/** Declaration of vertex and texture evaluators */
	glMap2f(GL_MAP2_VERTEX_3,0.0, 1.0, 3, 2 ,0.0, 1.0, 6, 2, &control_points[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &texture_points[0][0]);

	/** Enables automatic calculation of normals */
	glEnable(GL_AUTO_NORMAL);

	/** Enables the vertex and texture evaluators */
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	/** Defines the number of divisions of the grid */
	glMapGrid2f(divisions_u, 0.0,1.0, divisions_v, 0.0,1.0);

	/** Draw the whole thing */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glEvalMesh2(GL_FILL, 0,divisions_u, 0,divisions_v);
}

void Plane::setTexture(string file_texture)
{
	pixmap.readBMPFile(file_texture.c_str());
	int textureID = LaigScene::incrementTexCounter();
	pixmap.setTexture(textureID);
}