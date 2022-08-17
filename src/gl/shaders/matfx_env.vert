uniform mat4 u_texMatrix;
uniform vec4 u_colorClamp;
uniform vec4 u_envColor;

VSIN(ATTRIB_POS)	vec3 in_pos;

VSOUT vec4 v_color;
VSOUT vec4 v_envColor;
VSOUT vec2 v_tex0;
VSOUT vec2 v_tex1;
VSOUT float v_fog;

void
main(void)
{
	vec4 Vertex = u_world * vec4(in_pos, 1.0);
	/*gl_Position = u_proj * u_view * Vertex;
	vec3 Normal = mat3(u_world[0].xyz, u_world[1].xyz, u_world[2].xyz) * in_normal;

	v_tex0 = in_tex0;
	v_tex1 = (u_texMatrix * vec4(Normal, 1.0)).xy;

	v_color = in_color;
	v_color.rgb += u_ambLight.rgb*surfAmbient;
	v_color.rgb += DoDynamicLight(Vertex.xyz, Normal)*surfDiffuse;
	v_color = clamp(v_color, 0.0, 1.0);
	v_envColor = max(v_color, u_colorClamp) * u_envColor;
	v_color *= u_matColor;

	v_fog = DoFog(gl_Position.w);*/

	v_fog = 0.5f;
	v_tex0 = vec2(0.5f, 0.5f);
	v_tex1 = vec2(0.5f, 0.5f);
	v_color = vec4(1.0f, 0.0f, 1.0f, 0.0f);
 	v_envColor = vec4(1.0f, 0.0f, 1.0f, 0.0f);
	gl_Position = u_proj * u_view * Vertex;
}
