J::J(size_t pos){
    this->pos = pos;
}

void J::run(Estado &estado){
    estado.programCounter(this->pos);
}
