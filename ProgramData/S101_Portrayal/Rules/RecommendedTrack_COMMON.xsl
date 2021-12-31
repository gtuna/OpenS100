<?xml version="1.0" encoding="UTF-8"?>

<xsl:transform xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
   <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
   <xsl:template match="RecommendedTrack[@primitive='Curve']" priority="1">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECDEF02"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and (categoryOfRecommendedTrack=1 and (trafficFlow=1 or trafficFlow=2 or trafficFlow=3))]" priority="5">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC12"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and (categoryOfRecommendedTrack=1 and trafficFlow=4)]" priority="3">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC10"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and (categoryOfRecommendedTrack=2 and (trafficFlow=1 or trafficFlow=2 or trafficFlow=3))]" priority="5">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC11"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and (categoryOfRecommendedTrack=2 and trafficFlow=4)]" priority="3">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC09"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and (trafficFlow=1 or trafficFlow=2 or trafficFlow=3)]" priority="4">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC11"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
   <xsl:template match="RecommendedTrack[@primitive='Curve' and trafficFlow=4]" priority="2">
      <lineInstruction>
         <featureReference>
            <xsl:value-of select="@id"/>
         </featureReference>
         <viewingGroup>25020</viewingGroup>
         <displayPlane>OVERRADAR</displayPlane>
         <drawingPriority>18</drawingPriority>
         <lineStyleReference reference="RECTRC09"/>
      </lineInstruction>
      <xsl:if test="orientation/orientationValue!= ''">
         <textInstruction>
            <featureReference>
               <xsl:value-of select="@id"/>
            </featureReference>
            <viewingGroup>11</viewingGroup>
            <displayPlane>OVERRADAR</displayPlane>
            <drawingPriority>18</drawingPriority>
            <textLine horizontalAlignment="Center">
               <element>
                  <text>
                     <xsl:apply-templates select="orientation/orientationValue" mode="text"/>
                  </text>
                  <xsl:call-template name="textStyle">
                     <xsl:with-param name="style">default</xsl:with-param>
                  </xsl:call-template>
               </element>
               <startOffset>0.5</startOffset>
               <placementMode>Relative</placementMode>
            </textLine>
         </textInstruction>
      </xsl:if>
   </xsl:template>
</xsl:transform>
