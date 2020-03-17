#include "../include/JSpriteRenderer.h"

JSpriteRenderer::JSpriteRenderer(JShader & shader)
{
	this->shader = shader;
	initRenderData();

	shader.Use();
	modelLocation = glGetUniformLocation(shader.Program, "model");
	spriteRectLocation = glGetUniformLocation(shader.Program, "spriteRect");
	textureSizeLocation = glGetUniformLocation(shader.Program, "textureSize");
	colorLocation = glGetUniformLocation(shader.Program, "color");
	flippedLocation = glGetUniformLocation(shader.Program, "flipped");
}

JSpriteRenderer::~JSpriteRenderer()
{
	
}

void JSpriteRenderer::BindTexture(JTexture *tex, int textureFilter)
{
	glBindTexture(GL_TEXTURE_2D, tex->mTexId);

	if (textureFilter == TEX_FILTER_LINEAR)
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	else if (textureFilter == TEX_FILTER_NEAREST)
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void JSpriteRenderer::DrawSprite(JSprite &sprite)
{
	this->shader.Use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(sprite.position, 0.0f));
	model = glm::rotate(model, sprite.rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(sprite.scale, 1.0f));
	model = glm::translate(model, glm::vec3(-sprite.hotspot, 0.0f));
	model = glm::scale(model, glm::vec3(sprite.spriteRect[2], sprite.spriteRect[3], 1.0f));

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniform4f(spriteRectLocation, sprite.spriteRect.x, 
									sprite.spriteRect.y, 
									sprite.spriteRect.z, 
									sprite.spriteRect.w);

	glUniform2f(textureSizeLocation, 
				sprite.texture->mTexWidth, 
				sprite.texture->mTexHeight);

	glUniform2i(flippedLocation, 
				sprite.hFlipped, 
				sprite.vFlipped);

	glUniform4f(colorLocation, sprite.color.x, 
								sprite.color.y, 
								sprite.color.z, 
								sprite.color.w);

	glActiveTexture(GL_TEXTURE0);
	BindTexture(sprite.texture, sprite.textureFilter);
	glBindVertexArray(this->quadVAO);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(0);
}

void JSpriteRenderer::initRenderData()
{
	// Configure VAO/VBO
	GLuint VBO;
	GLfloat vertices[] = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};
	glGenVertexArrays(1, &this->quadVAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindVertexArray(this->quadVAO);
	GLint vertexLocation = glGetAttribLocation(this->shader.Program, "vertex");
	glEnableVertexAttribArray(vertexLocation);
	glVertexAttribPointer(vertexLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
