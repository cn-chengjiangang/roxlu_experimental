#include <roxlu/opengl/Billboard.h>

#ifdef ROXLU_WITH_OPENGL

namespace roxlu {

  Shader Billboard::shader = Shader();
  bool Billboard::created = false;
  GLuint Billboard::vbo = 0;
  GLuint Billboard::vao = 0;

  Billboard::Billboard()
    :texture(NULL)
    ,texture_set(false)
    ,mode(BILLBOARD_PERSPECTIVE)
  {
  }

  void Billboard::bind(const float* pm, const float* vm) {

    if(!texture_set) {
      printf("Cannot use billboard w/o texture.\n");
    }
	
    mode = BILLBOARD_NONE;
	
    this->vm = vm;
    this->pm = pm;

    initBillboard();	
  }


  void Billboard::bind(const float* pm, const float* vm, const float* right, const float* up) {
    if(!texture_set) {
      printf("Cannot use billboard w/o texture.\n");
    }
	
    mode = BILLBOARD_PERSPECTIVE;
	
    this->right = right;
    this->up = up;
    this->pm = pm;
    this->vm = vm;

    initBillboard();
  }

  void Billboard::initBillboard() {
    if(!created) {
      //vao.create();
      glGenVertexArrays(1, &vao);
      glBindVertexArray(vao);

      printf("Billboard needs to be created\n");
		
      if(!shader.create(BILLBOARD_VS, BILLBOARD_FS)) {
        printf("Cannot create billboard shader.\n");
        ::exit(0);
      }

      shader.a("a_pos", 0).a("a_tex", 1);
      shader.link();
      shader.u("u_projection_matrix").u("u_view_matrix").u("u_model_matrix").u("u_texture").u("u_alpha");
		
      glGenBuffers(1, &vbo); eglGetError();
      glBindBuffer(GL_ARRAY_BUFFER, vbo); eglGetError();		
		
      BillboardVertex vertices[6];
      float s = 0.5f;
      vertices[0].set(-s, -s, 0.0f, 0.0f);
      vertices[1].set(s, -s, 1.0f, 0.0f);
      vertices[2].set(s, s, 1.0f, 1.0f);
		
      vertices[3].set(-s, -s, 0.0f, 0.0f);
      vertices[4].set(s, s, 1.0f, 1.0f);
      vertices[5].set(-s, s, 0.0f, 1.0f);

		
      glBufferData(GL_ARRAY_BUFFER, sizeof(BillboardVertex) * 6, &(vertices[0].pos[0]), GL_STATIC_DRAW);
	
      glEnableVertexAttribArray(0); eglGetError();
      glEnableVertexAttribArray(1); eglGetError();

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(BillboardVertex), (GLvoid*)offsetof(BillboardVertex, pos));
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(BillboardVertex), (GLvoid*)offsetof(BillboardVertex, tex));

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);
      shader.disable();
      created = true;
		
    }

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE2); eglGetError();
    glBindTexture(GL_TEXTURE_2D, tex); eglGetError();
	
    shader.enable();
    shader.uniformMat4fv("u_projection_matrix", pm);
    shader.uniformMat4fv("u_view_matrix", vm);
    shader.uniform1i("u_texture",2);
  }

  void Billboard::setTexture(const GLuint& id) {
    tex = id;
    texture_set = true;
  }


  void Billboard::draw(const Vec3& position, const float scale, const float rotationDegrees, float alpha) {	
    Mat4 mm;
	
    if(mode == BILLBOARD_PERSPECTIVE) {
      mm.setBillboard(right,up);
    }

    mm.setPosition(position);
    mm.scale(scale);

    if(rotationDegrees > 0) {
      Quat q;
      q.fromAngleAxis(rotationDegrees * DEG_TO_RAD,0,0,1); // @todo test new quat implementation
      mm = mm * q.getMat4();
    }
	
    shader.uniform1f("u_alpha", alpha);
    shader.uniformMat4fv("u_model_matrix", mm.getPtr());
	
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
  }

  void Billboard::unbind() {
    glBindVertexArray(0);
    shader.disable();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

} // roxlu

#endif // ROXLU_WITH_OPENGL
