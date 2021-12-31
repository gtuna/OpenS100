-- Converter Version: 0.99
-- Feature Catalogue Version: 1.0.0 (2018/9/6)

-- Radar line main entry point.
function RadarLine(feature, featurePortrayal, contextParameters)
	if feature.PrimitiveType == PrimitiveType.Curve then
		if contextParameters.RADAR_OVERLAY then
			featurePortrayal:AddInstructions('ViewingGroup:25040;DrawingPriority:6;DisplayPlane:OverRADAR')
		else
			featurePortrayal:AddInstructions('ViewingGroup:25040;DrawingPriority:6;DisplayPlane:UnderRADAR')
		end
		featurePortrayal:SimpleLineStyle('dash',0.64,'TRFCD')
		featurePortrayal:AddInstructions('LineInstruction:')
		featurePortrayal:AddInstructions('LocalOffset:0,3.51;TextAlignHorizontal:Center;FontSize:10;TextInstruction:' .. EncodeString(feature.orientationValue, '%03.0f deg') .. ',11,8')
	else
		error('Invalid primitive type or mariner settings passed to portrayal')
	end
end
