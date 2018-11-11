#version 420 core

in defaultBlock
{
	vec4 position;
	vec2 UV;
} inBlock;

out vec4 outColor;

void main()
{
	outColor = vec4(1.0, 1.0, 0.0, 1.0);
}