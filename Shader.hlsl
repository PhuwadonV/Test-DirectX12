struct Light {
	float4 color;
	float3 pos;
};

#define NUM_LIGHTS 1

cbuffer ConstBuff : register(b0) {
	float4x4 g_world;
	float4x4 g_worldInvTranpose;
	float4x4 g_worldViewProj;
	float4 g_eyePos;
	float4 g_lightPos;
};

float4 VS(float3 pos : POS,
		  inout float3 color : COLOR,
		  inout float3 normal : NORMAL,
		  out float3 wPos : WORLD_POS) : SV_POSITION {

	wPos = mul(float4(pos, 1.0f), g_world);
	float4 nPos = mul(float4(pos, 1.0f), g_worldViewProj);
	normal = mul(normal, (float3x3)g_worldInvTranpose);

	return nPos;
}

float4 PS(float4 pos : SV_POSITION,
		  float3 color : COLOR,
		  float3 normal : NORMAL,
		  float3 wPos : WORLD_POS) : SV_TARGET {

	float3 lightVec = g_lightPos - wPos;
	float lightVecDist = length(lightVec);
	lightVec /= lightVecDist;

	float fallOff = 1.0f / (lightVecDist * lightVecDist);
	float LdotN = dot(normal, lightVec);
	float HdotN = dot(normal, normalize(lightVec + normalize(g_eyePos - wPos)));
	float intensity = 20;
	float4 mat = float4(color, 0.0f);
	return mat * LdotN * fallOff * intensity + mat * fallOff * intensity + mat * fallOff * pow(HdotN, 50) * 50;
}