<?xml version="1.0" encoding="UTF-8"?>

<xsl:transform xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
   <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
   <xsl:template match="LocalMagneticAnomaly[@primitive='Surface']" priority="1">
      <pointInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>31080</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>12</drawingPriority>
         <symbol reference="LOCMAG51">
            <areaPlacement placementMode="VisibleParts"/>
         </symbol>
      </pointInstruction>
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>31080</viewingGroup>
         <displayPlane>UNDERRADAR</displayPlane>
         <drawingPriority>12</drawingPriority>
         <lineStyleReference reference="NAVARE51"/>
      </lineInstruction>
   </xsl:template>
</xsl:transform>
