## avr-fet
Za svaki novi projekat potrebno je konfigurisati Makefile i to u sekciji Makefile-a koja je oznacena sa: "Project-specific Details".
Najbitnije je odabrati odgovarajuci MCU i DEVICE u Makefile-u. Ako se uvijek koristi isti MCU onda se ovi parametri podese samo jednom.

U zavisnosti od projekta na kojem se radi potrebno je u LOCAL_SOURCE specificirati dodate file-ove koje je potrebno kompajlirati.
Moze se vidjeti u primjerima na koji nacin se ove stvari specificiraju.

Za kompajliranje koda koristi se komanda 'make', a za upload koda na MCU koristi se 'make flash'.

