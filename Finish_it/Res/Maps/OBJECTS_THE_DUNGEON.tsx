<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.2.4" name="OBJECTS_THE_DUNGEON" tilewidth="128" tileheight="168" tilecount="27" columns="0">
 <grid orientation="orthogonal" width="1" height="1"/>
 <tile id="0">
  <image width="46" height="67" source="../Textures/Banner (1).png"/>
 </tile>
 <tile id="1">
  <image width="47" height="99" source="../Textures/Banner (2).png"/>
 </tile>
 <tile id="2">
  <image width="58" height="74" source="../Textures/Barrel (1).png"/>
  <objectgroup draworder="index">
   <object id="1" x="1" y="1" width="55.25" height="64"/>
  </objectgroup>
 </tile>
 <tile id="3">
  <image width="58" height="74" source="../Textures/Barrel (2).png"/>
  <objectgroup draworder="index">
   <object id="6" x="0.875" y="0.75" width="55.25" height="64"/>
  </objectgroup>
 </tile>
 <tile id="4">
  <image width="58" height="74" source="../Textures/Barrel (3).png"/>
  <objectgroup draworder="index">
   <object id="6" x="1" y="1" width="56" height="64"/>
  </objectgroup>
 </tile>
 <tile id="5">
  <image width="55" height="63" source="../Textures/Crate.png"/>
  <objectgroup draworder="index">
   <object id="1" x="5" y="0" width="45" height="55"/>
  </objectgroup>
 </tile>
 <tile id="6" type="GOLDEN_KEY">
  <image width="35" height="36" source="../Textures/Objects/Collectable/golden_key.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="35" height="36">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="7" type="IRON_KEY">
  <image width="35" height="36" source="../Textures/Objects/Collectable/iron_key.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="35" height="36">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="8" type="STAIR_UP">
  <image width="128" height="64" source="../Textures/stair_up.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="128" height="64">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="9" type="STAIR_DOWN">
  <image width="128" height="64" source="../Textures/stair_down.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="128" height="64">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="10">
  <image width="45" height="62" source="../Textures/Pot (1).png"/>
  <objectgroup draworder="index">
   <object id="2" x="2" y="15" width="40" height="40">
    <ellipse/>
   </object>
   <object id="4" x="8" y="0" width="28" height="28">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="11">
  <image width="45" height="61" source="../Textures/Pot (2).png"/>
  <objectgroup draworder="index">
   <object id="1" x="2" y="15" width="40" height="40">
    <ellipse/>
   </object>
   <object id="2" x="8" y="0" width="28" height="28">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="12">
  <image width="57" height="47" source="../Textures/Skeleton1.png"/>
  <objectgroup draworder="index">
   <object id="1" x="11" y="-1" width="35" height="35">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="13">
  <image width="54" height="37" source="../Textures/Skeleton2.png"/>
 </tile>
 <tile id="17" type="TORCH">
  <properties>
   <property name="isOn" type="bool" value="true"/>
  </properties>
  <image width="69" height="62" source="../Textures/Lightings/iconTorch.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="69" height="62">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="19" type="TORCH">
  <properties>
   <property name="isOn" type="bool" value="false"/>
  </properties>
  <image width="69" height="62" source="../Textures/Lightings/iconTorchOff.png"/>
  <objectgroup draworder="index">
   <object id="1" type="TORCH" x="0" y="0" width="69" height="62">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="20" type="WINDOW_TORCH">
  <properties>
   <property name="isOn" type="bool" value="false"/>
  </properties>
  <image width="40" height="72" source="../Textures/Lightings/iconWindowTorchOff.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.5" y="0" width="40.25" height="75">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="21" type="WINDOW_TORCH">
  <properties>
   <property name="isOn" type="bool" value="true"/>
  </properties>
  <image width="40" height="72" source="../Textures/Lightings/iconWindowTorchOn.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.625" y="-0.25" width="40.25" height="75">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="22" type="GOLDEN_CHEST">
  <image width="76" height="73" source="../Textures/Chests/3.png"/>
  <objectgroup draworder="index">
   <object id="1" x="3.5" y="12" width="64.5" height="52"/>
   <object id="2" x="-2.25" y="5.5" width="75.75" height="63.25">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="23" type="ITEM_CHEST">
  <image width="76" height="73" source="../Textures/Chests/3-copy-0.png"/>
  <objectgroup draworder="index">
   <object id="1" x="4" y="11.5" width="63.5" height="53.25"/>
   <object id="2" x="-1.625" y="5.875" width="75.75" height="63.25">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="24" type="DOUBLE_WOOD_DOOR">
  <image width="128" height="167" source="../Textures/Doors/1-copy-2.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="128" height="167">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
   <object id="2" x="-2" y="116" width="132" height="28"/>
  </objectgroup>
 </tile>
 <tile id="25" type="IRON_DOOR">
  <image width="64" height="135" source="../Textures/Doors/ironDoorTiled.png"/>
  <objectgroup draworder="index">
   <object id="1" x="-6.25" y="92.75" width="77" height="30.75"/>
  </objectgroup>
 </tile>
 <tile id="26" type="WOOD_DOOR">
  <image width="64" height="168" source="../Textures/Doors/1-copy-4.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="64" height="168">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
   <object id="2" x="-6" y="107" width="77.5" height="38.5"/>
  </objectgroup>
 </tile>
 <tile id="27" type="PIKE_TRAP">
  <properties>
   <property name="isOn" type="bool" value="false"/>
  </properties>
  <image width="64" height="66" source="../Textures/FloorButtons/1.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="64" height="66">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="28" type="LEVER">
  <image width="104" height="73" source="../Textures/FloorButtons/1-copy-5.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="104" height="73">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="29" type="PRESSURE_PLATE">
  <image width="64" height="64" source="../Textures/FloorButtons/Button (1).png"/>
  <objectgroup draworder="index">
   <object id="1" x="8.25" y="4.25" width="46.75" height="44.875">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
 <tile id="30" type="PIKE_TRAP">
  <properties>
   <property name="isOn" type="bool" value="true"/>
  </properties>
  <image width="64" height="66" source="../Textures/FloorButtons/2.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0" y="0" width="64" height="66">
    <properties>
     <property name="isSensor" type="bool" value="true"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
</tileset>
