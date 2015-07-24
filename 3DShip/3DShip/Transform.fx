
// HLSL - High Level Shading Language

// Effet de post-process

// Types
// float
// float2
// float3
// float4
// float4x4
// int
// bool

uniform extern float4x4 gWVP;
uniform extern float gTime;
uniform extern float3 gEyePos;
uniform extern float4 gFogColor;

float minDist = 0.0f;
float maxDist = 100.0f;

// Amplitude
static float a[2] = { 0.8f, 0.2f };

// Angular Wave number
static float k[2] = { 1.0f, 8.0f };

// Angular frequency
static float w[2] = { 1.0f, 8.0f };

// Phase shift
static float p[2] = { 0.0f, 1.0f };


struct OutputVS
{
				// SEMANTIC
	float4 posH: POSITION0;
	float4 color: COLOR0;
	float fogLerp : TEXCOORD3;
};

float SumOfRadialSineWave(float x, float z)
{
	// Distance of the vertex from the wave source
	float d = sqrt(x*x + z*z);

	// Sum the waves;
	float sum = 0.0f;
	for (int i = 0; i < 2; i++)
	{
		sum += a[i] * sin(k[i] * d - gTime*w[i] + p[i]);
	}
	return sum;
}

float4 GetColorFromZ(float z)
{
	if (abs(z) <= 0.0f)
		return float4(0.48f, 0.77f, 0.46f, 1.0f);
	else if (abs(z) <= 0.20f)
		return float4(1.0f, 0.0f, 0.0f, 1.0f); 
	else if (abs(z) <= 0.60f)
		return float4(1.0f, 0.0f, 0.0f, 1.0f); 
	else if (abs(z) <= 0.80f)
		return float4(1.0f, 0.0f, 0.0f, 1.0f); 
	else
		return float4(1.0f, 1.0f, 0.0f, 1.0f);
}

// Fonction VertexShader
OutputVS TransformSineVS(float3 posL: POSITION0, float4 color : COLOR0)
{
	OutputVS outVS = (OutputVS)0;

	outVS.posH = mul(float4(posL, 1.0f), gWVP);
	outVS.color = GetColorFromZ(posL.z);

	float dist = distance(outVS.posH, gEyePos);
	outVS.fogLerp = saturate((dist - minDist) / (maxDist - minDist));

	return outVS;
}

OutputVS TransformVS(float3 posL: POSITION0, float4 color: COLOR0)
{
	OutputVS outVS = (OutputVS)0;
	outVS.posH = mul(float4(posL, 1.0f), gWVP);
	outVS.color = GetColorFromZ(posL.z);

	float dist = distance(outVS.posH, gEyePos);
	outVS.fogLerp = saturate((dist - minDist) / (maxDist - minDist));

	return outVS;
}

OutputVS TransformVS_Scale(float3 posL: POSITION0, float4 color : COLOR0)
{
	OutputVS outVS = (OutputVS)0;
	outVS.posH = mul(float4(posL * 1.01f, 1.0f), gWVP);
	outVS.color = color;
	return outVS;
}

OutputVS TransformVS_Ship(float3 posL: POSITION0, float4 color : COLOR0)
{
	OutputVS outVS = (OutputVS)0;
	outVS.posH = mul(float4(posL, 1.0f), gWVP);

	return outVS;
}

float4 TransformPS(OutputVS inVS): COLOR0
{
	float4 finalColor = lerp(inVS.color, gFogColor, inVS.fogLerp);
	return finalColor;
}

float4 TransformPS_Black(OutputVS inVS) : COLOR0
{
	return (float4)0;
}

float4 TransformPS_Ship(OutputVS inVS) : COLOR0
{
	return float4(1.f, 0.f, 0.f, 1.f);
}
 
// Techniques
technique TransformTech
{
	pass P0
	{
		vertexShader = compile vs_2_0 TransformVS();
		pixelShader = compile ps_2_0 TransformPS();

		FillMode = Solid;
	}

	pass P1
	{
		vertexShader = compile vs_2_0 TransformVS();
		pixelShader = compile ps_2_0 TransformPS_Black();
		FillMode = WireFrame;
	}
}

technique TransformTechSine
{
	pass P0
	{
		vertexShader = compile vs_2_0 TransformSineVS();
		pixelShader = compile ps_2_0 TransformPS();
		FillMode = Solid;
	}

	pass P1
	{
		vertexShader = compile vs_2_0 TransformSineVS();
		pixelShader = compile ps_2_0 TransformPS_Black();
		FillMode = WireFrame;
	}
}

technique TransformTechShip
{
	pass P0
	{
		vertexShader = compile vs_2_0 TransformVS_Ship();
		pixelShader = compile ps_2_0 TransformPS_Ship();

		FillMode = Solid;
	}

	pass P1
	{
		vertexShader = compile vs_2_0 TransformVS();
		pixelShader = compile ps_2_0 TransformPS_Black();
		FillMode = WireFrame;
	}
}

technique TransformTechTunnel
{
	pass P0
	{
		vertexShader = compile vs_2_0 TransformSineVS();
		pixelShader = compile ps_2_0 TransformPS();

		FillMode = Solid;
	}

	pass P1
	{
		vertexShader = compile vs_2_0 TransformVS();
		pixelShader = compile ps_2_0 TransformPS_Black();
		FillMode = WireFrame;
	}
}