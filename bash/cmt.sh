# bash/cmt.sh
# Guarda se ci sono opzioni
while getopts "m:h" opt; do
    case $opt in
        m)
            messaggio=" - $OPTARG" # assegno la stringa passata come parametro
            echo "Messaggio personalizzato: $messaggio"
            ;;
        h)
            echo "  -m  (messaggio): aggiungi un messaggio personale al commit oltre a quello di default"
            exit 0
            ;;
        \?)
            echo "Opzione non valida: -$OPTARG" >&2
            echo "Uso: $0 [-m messaggio]"
            echo "  -m  (messaggio): aggiungi un messaggio personale al commit oltre a quello di default"
            exit 1
            ;;
    esac
done

# Aggiungi tutti i file al commit
git add .
# Mostra lo stato dei file
git status

# Crea il nome del commit con data, ora e versione
nomeCommit="aggiornamento $(date "+%Y %m %d %H:%M")"
echo "Messaggio commit: $nomeCommit"
git commit -am "$nomeCommit$messaggio"

# Esegui il push sul repository remoto
git push -f

sleep 1