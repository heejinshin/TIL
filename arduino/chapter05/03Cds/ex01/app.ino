
const byte cds = A5;
void setup()
{
    Serial.begin(115200);
}

void loop(){
    int ad_cds;
    float v_cds;

    ad_cds = analogRead(cds);

    v_cds = (float)ad_cds / 1024.0 *5;

    Serial.print("AD_CDS =");
    Serial.println(ad_cds);

    Serial.print("V_CDS = ");
    Serial.println(v_cds);
    Serial.println(" ");
    delay(1000);
}